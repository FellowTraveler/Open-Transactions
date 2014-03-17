#include "stdafx.h"

#include "ot_me_switch.hpp"


int noAltPathways = INT_MAX;

int OtMeTest::pathways = 0;
int OtMeTest::singles = 0;


OtMeTest::OtMeTest()
: mock(*new StrictMock<Mock_OTAPI_Exec>())
#if USE_OLD_CHAISCRIPT
, me(* new OtMeChai)
#else
, me(* new OtMeExtra)
#endif
{
	// default behavior follows max positive path
	index = INT_MAX;

	savePathways = pathways;
}

OtMeTest::~OtMeTest()
{
	if (savePathways == pathways)
	{
		// normal test, is also a single pathway
		pathways++;
		singles++;
	}
    delete &me;
	delete &mock;
}

time_t OtMeTest::GetTime()
{
	return mock.GetTime();
}

void OtMeTest::SetUp()
{
}

void OtMeTest::TearDown()
{
	remove("C:/Users/Eric/AppData/Roaming/OpenTransactions/client_data/ot.pid");
}

void OtMeTest::TestAllPathways(TestFunc testFunc)
{
	index = -1;
	for (int i = 0; index < 0; i++)
	{
		cout << "\n********** Pathway " << i << " **********\n\n";
		StrictMock<Mock_OTAPI_Exec> & mock = *new StrictMock<Mock_OTAPI_Exec>();
		index = i;
		testFunc(mock, me, index);
		delete &mock;
		pathways++;
	}
}

void OtMeTest::TestFullPathway(TestFunc testFunc)
{
	// follow max positive path
	index = INT_MAX;
	testFunc(mock, me, index);
}

void OtMeTest::EXPECT_details_withdraw_cash(Mock_OTAPI_Exec & mock, int & index, const char * accountId, const int64_t amount)
{
	EXPECT_MULTI_RETURN("", NYM_ID, GetAccountWallet_NymID(ACCOUNT_ID));

	EXPECT_MULTI_RETURN("", ASSET_ID, GetAccountWallet_AssetTypeID(ACCOUNT_ID));

	EXPECT_MULTI_RETURN("", SERVER_ID, GetAccountWallet_ServerID(ACCOUNT_ID));

	if (index >= 0)
	{
		// force fail
		EXPECT_CALL_RETURN("", LoadAssetContract(ASSET_ID));

		EXPECT_REQUEST(MESSAGE_DATA, getContract(SERVER_ID, NYM_ID, ASSET_ID));

		EXPECT_MULTI_RETURN(OT_ERROR, OT_TRUE, Message_GetSuccess(MESSAGE_DATA));

		EXPECT_MULTI_RETURN("", CONTRACT_DATA, LoadAssetContract(ASSET_ID));

		EXPECT_MULTI_RETURN(true, false, Mint_IsStillGood(SERVER_ID, ASSET_ID));

		if (index >= 0)
		{
			EXPECT_REQUEST(MESSAGE_DATA, getMint(SERVER_ID, NYM_ID, ASSET_ID));

			EXPECT_MULTI_RETURN(OT_FALSE, OT_TRUE, Message_GetSuccess(MESSAGE_DATA));

			EXPECT_MULTI_RETURN(false, true, Mint_IsStillGood(SERVER_ID, ASSET_ID));
		}
		else
		{
			// make sure to take BOTH paths in next call
			index++;
		}

		EXPECT_MULTI_RETURN("", MINT_DATA, LoadMint(SERVER_ID, ASSET_ID));

		if (index >= 0)
		{
			EXPECT_TRANSACTION(MESSAGE_DATA, notarizeWithdrawal(SERVER_ID, NYM_ID, ACCOUNT_ID, AMOUNT));

			EXPECT_InterpretTransactionMsgReply(mock, index, SERVER_ID, NYM_ID, ACCOUNT_ID);

			if (index >= 0)
			{
				EXPECT_getIntermediaryFiles(mock, index, SERVER_ID, NYM_ID, ACCOUNT_ID, false);
			}
		}
	}
}

void OtMeTest::EXPECT_getIntermediaryFiles(Mock_OTAPI_Exec & mock, int & index, const char * serverId, const char * nymId, const char * accountId, bool bForced)
{
	EXPECT_REQUEST_SN(MESSAGE_DATA, getAccountFiles(serverId, nymId, accountId), serverId, nymId);

	EXPECT_CALL_RETURN(LEDGER_DATA, LoadInboxNoVerify(serverId, nymId, accountId));

	EXPECT_CALL_RETURN(true, VerifySignature(nymId, LEDGER_DATA));

	EXPECT_CALL_RETURN(0, Ledger_GetCount(serverId, nymId, accountId, LEDGER_DATA));

	EXPECT_CALL_RETURN(LEDGER_DATA, LoadOutboxNoVerify(serverId, nymId, accountId));

	EXPECT_CALL_RETURN(true, VerifySignature(nymId, LEDGER_DATA));

	EXPECT_CALL_RETURN(0, Ledger_GetCount(serverId, nymId, accountId, LEDGER_DATA));
}

void OtMeTest::EXPECT_InterpretTransactionMsgReply(Mock_OTAPI_Exec & mock, int & index, const char * serverId, const char * nymId, const char * accountId)
{
	EXPECT_MULTI_RETURN(OT_ERROR, OT_TRUE, Message_GetSuccess(MESSAGE_DATA));

	EXPECT_MULTI_RETURN(OT_ERROR, OT_TRUE, Message_GetBalanceAgreementSuccess(serverId, nymId, accountId, MESSAGE_DATA));

	EXPECT_MULTI_RETURN(OT_ERROR, OT_TRUE, Message_GetTransactionSuccess(serverId, nymId, accountId, MESSAGE_DATA));
}
