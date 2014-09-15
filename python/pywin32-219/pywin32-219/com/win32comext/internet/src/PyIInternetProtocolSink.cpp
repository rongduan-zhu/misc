// This file implements the IInternetProtocolSink Interface and Gateway for Python.
// Generated by makegw.py

#include "internet_pch.h"
#include "PyIInternetProtocolSink.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIInternetProtocolSink::PyIInternetProtocolSink(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIInternetProtocolSink::~PyIInternetProtocolSink()
{
}

/* static */ IInternetProtocolSink *PyIInternetProtocolSink::GetI(PyObject *self)
{
	return (IInternetProtocolSink *)PyIUnknown::GetI(self);
}

// @pymethod |PyIInternetProtocolSink|Switch|Description of Switch.
PyObject *PyIInternetProtocolSink::Switch(PyObject *self, PyObject *args)
{
	IInternetProtocolSink *pIIPS = GetI(self);
	if ( pIIPS == NULL )
		return NULL;
// *** The input argument pProtocolData of type "PROTOCOLDATA __RPC_FAR *" was not processed ***
//     Please check the conversion function is appropriate and exists!
	PROTOCOLDATA pProtocolData;
	PyObject *obpProtocolData;
	if ( !PyArg_ParseTuple(args, "O:Switch", &obpProtocolData) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (bPythonIsHappy && !PyObject_AsPROTOCOLDATA( obpProtocolData, &pProtocolData )) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIIPS->Switch( &pProtocolData );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIInternetProtocolSink|ReportProgress|Description of ReportProgress.
PyObject *PyIInternetProtocolSink::ReportProgress(PyObject *self, PyObject *args)
{
	IInternetProtocolSink *pIIPS = GetI(self);
	if ( pIIPS == NULL )
		return NULL;
	// @pyparm int|ulStatusCode||Description for ulStatusCode
	// @pyparm <o unicode>|szStatusText||Description for szStatusText
	PyObject *obszStatusText;
	ULONG ulStatusCode;
	LPWSTR szStatusText;
	if ( !PyArg_ParseTuple(args, "iO:ReportProgress", &ulStatusCode, &obszStatusText) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_BstrFromPyObject(obszStatusText, &szStatusText)) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIIPS->ReportProgress( ulStatusCode, szStatusText );
	PY_INTERFACE_POSTCALL;
	SysFreeString(szStatusText);

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIInternetProtocolSink|ReportData|Description of ReportData.
PyObject *PyIInternetProtocolSink::ReportData(PyObject *self, PyObject *args)
{
	IInternetProtocolSink *pIIPS = GetI(self);
	if ( pIIPS == NULL )
		return NULL;
	// @pyparm int|grfBSCF||Description for grfBSCF
	// @pyparm int|ulProgress||Description for ulProgress
	// @pyparm int|ulProgressMax||Description for ulProgressMax
	DWORD grfBSCF;
	ULONG ulProgress;
	ULONG ulProgressMax;
	if ( !PyArg_ParseTuple(args, "iii:ReportData", &grfBSCF, &ulProgress, &ulProgressMax) )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIIPS->ReportData( grfBSCF, ulProgress, ulProgressMax );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIInternetProtocolSink|ReportResult|Description of ReportResult.
PyObject *PyIInternetProtocolSink::ReportResult(PyObject *self, PyObject *args)
{
	IInternetProtocolSink *pIIPS = GetI(self);
	if ( pIIPS == NULL )
		return NULL;
	// @pyparm int|hrResult||Description for hrResult
	// @pyparm int|dwError||Description for dwError
	// @pyparm <o unicode>|szResult||Description for szResult
	PyObject *obszResult;
	HRESULT hrResult;
	DWORD dwError;
	LPWSTR szResult;
	if ( !PyArg_ParseTuple(args, "iiO:ReportResult", &hrResult, &dwError, &obszResult) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_BstrFromPyObject(obszResult, &szResult)) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIIPS->ReportResult( hrResult, dwError, szResult );
	PY_INTERFACE_POSTCALL;
	SysFreeString(szResult);

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @object PyIInternetProtocolSink|Description of the interface
static struct PyMethodDef PyIInternetProtocolSink_methods[] =
{
	{ "Switch", PyIInternetProtocolSink::Switch, 1 }, // @pymeth Switch|Description of Switch
	{ "ReportProgress", PyIInternetProtocolSink::ReportProgress, 1 }, // @pymeth ReportProgress|Description of ReportProgress
	{ "ReportData", PyIInternetProtocolSink::ReportData, 1 }, // @pymeth ReportData|Description of ReportData
	{ "ReportResult", PyIInternetProtocolSink::ReportResult, 1 }, // @pymeth ReportResult|Description of ReportResult
	{ NULL }
};

PyComTypeObject PyIInternetProtocolSink::type("PyIInternetProtocolSink",
		&PyIUnknown::type,
		sizeof(PyIInternetProtocolSink),
		PyIInternetProtocolSink_methods,
		GET_PYCOM_CTOR(PyIInternetProtocolSink));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGInternetProtocolSink::Switch(
		/* [in] */ PROTOCOLDATA __RPC_FAR * pProtocolData)
{
	PY_GATEWAY_METHOD;
// *** The input argument pProtocolData of type "PROTOCOLDATA __RPC_FAR *" was not processed ***
//   - Please ensure this conversion function exists, and is appropriate
//   - The type 'PROTOCOLDATA' (pProtocolData) is unknown.
	PyObject *obpProtocolData = PyObject_FromPROTOCOLDATA(pProtocolData);
	if (obpProtocolData==NULL) return PyCom_HandlePythonFailureToCOM();
	HRESULT hr=InvokeViaPolicy("Switch", NULL, "O", obpProtocolData);
	Py_DECREF(obpProtocolData);
	return hr;
}

STDMETHODIMP PyGInternetProtocolSink::ReportProgress(
		/* [in] */ ULONG ulStatusCode,
		/* [in] */ LPCWSTR szStatusText)
{
	PY_GATEWAY_METHOD;
	PyObject *obszStatusText;
	obszStatusText = MakeOLECHARToObj(szStatusText);
	HRESULT hr=InvokeViaPolicy("ReportProgress", NULL, "iO", ulStatusCode, obszStatusText);
	Py_XDECREF(obszStatusText);
	return hr;
}

STDMETHODIMP PyGInternetProtocolSink::ReportData(
		/* [in] */ DWORD grfBSCF,
		/* [in] */ ULONG ulProgress,
		/* [in] */ ULONG ulProgressMax)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("ReportData", NULL, "iii", grfBSCF, ulProgress, ulProgressMax);
	return hr;
}

STDMETHODIMP PyGInternetProtocolSink::ReportResult(
		/* [in] */ HRESULT hrResult,
		/* [in] */ DWORD dwError,
		/* [in] */ LPCWSTR szResult)
{
	PY_GATEWAY_METHOD;
	PyObject *obszResult;
	obszResult = MakeOLECHARToObj(szResult);
	HRESULT hr=InvokeViaPolicy("ReportResult", NULL, "iiO", hrResult, dwError, obszResult);
	Py_XDECREF(obszResult);
	return hr;
}

