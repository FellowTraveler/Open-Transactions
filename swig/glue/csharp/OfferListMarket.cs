/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace OpenTransactions.OTAPI {

public class OfferListMarket : Storable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal OfferListMarket(global::System.IntPtr cPtr, bool cMemoryOwn) : base(otapiPINVOKE.OfferListMarket_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(OfferListMarket obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~OfferListMarket() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          otapiPINVOKE.delete_OfferListMarket(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public uint GetBidDataCount() {
    uint ret = otapiPINVOKE.OfferListMarket_GetBidDataCount(swigCPtr);
    return ret;
  }

  public BidData GetBidData(uint nIndex) {
    global::System.IntPtr cPtr = otapiPINVOKE.OfferListMarket_GetBidData(swigCPtr, nIndex);
    BidData ret = (cPtr == global::System.IntPtr.Zero) ? null : new BidData(cPtr, false);
    return ret;
  }

  public bool RemoveBidData(uint nIndexBidData) {
    bool ret = otapiPINVOKE.OfferListMarket_RemoveBidData(swigCPtr, nIndexBidData);
    return ret;
  }

  public bool AddBidData(BidData disownObject) {
    bool ret = otapiPINVOKE.OfferListMarket_AddBidData(swigCPtr, BidData.getCPtr(disownObject));
    if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public uint GetAskDataCount() {
    uint ret = otapiPINVOKE.OfferListMarket_GetAskDataCount(swigCPtr);
    return ret;
  }

  public AskData GetAskData(uint nIndex) {
    global::System.IntPtr cPtr = otapiPINVOKE.OfferListMarket_GetAskData(swigCPtr, nIndex);
    AskData ret = (cPtr == global::System.IntPtr.Zero) ? null : new AskData(cPtr, false);
    return ret;
  }

  public bool RemoveAskData(uint nIndexAskData) {
    bool ret = otapiPINVOKE.OfferListMarket_RemoveAskData(swigCPtr, nIndexAskData);
    return ret;
  }

  public bool AddAskData(AskData disownObject) {
    bool ret = otapiPINVOKE.OfferListMarket_AddAskData(swigCPtr, AskData.getCPtr(disownObject));
    if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public new static OfferListMarket ot_dynamic_cast(Storable pObject) {
    global::System.IntPtr cPtr = otapiPINVOKE.OfferListMarket_ot_dynamic_cast(Storable.getCPtr(pObject));
    OfferListMarket ret = (cPtr == global::System.IntPtr.Zero) ? null : new OfferListMarket(cPtr, false);
    return ret;
  }

}

}
