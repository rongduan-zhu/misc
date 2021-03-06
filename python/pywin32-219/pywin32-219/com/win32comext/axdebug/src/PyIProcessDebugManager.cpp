// This file implements the IProcessDebugManager Interface and Gateway for Python.
// Generated by makegw.py

#include "stdafx.h"
#include "PyIProcessDebugManager.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIProcessDebugManager::PyIProcessDebugManager(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIProcessDebugManager::~PyIProcessDebugManager()
{
}

/* static */ IProcessDebugManager *PyIProcessDebugManager::GetI(PyObject *self)
{
	return (IProcessDebugManager *)PyIUnknown::GetI(self);
}

// @pymethod |PyIProcessDebugManager|CreateApplication|Description of CreateApplication.
PyObject *PyIProcessDebugManager::CreateApplication(PyObject *self, PyObject *args)
{
	IProcessDebugManager *pIPDM = GetI(self);
	if ( pIPDM == NULL )
		return NULL;
	IDebugApplication *ppda;
	if ( !PyArg_ParseTuple(args, ":CreateApplication") )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIPDM->CreateApplication( &ppda );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self,hr);
	return PyCom_PyObjectFromIUnknown(ppda, IID_IDebugApplication, FALSE);
}

// @pymethod |PyIProcessDebugManager|GetDefaultApplication|Description of GetDefaultApplication.
PyObject *PyIProcessDebugManager::GetDefaultApplication(PyObject *self, PyObject *args)
{
	IProcessDebugManager *pIPDM = GetI(self);
	if ( pIPDM == NULL )
		return NULL;
	IDebugApplication *ppda;
	if ( !PyArg_ParseTuple(args, ":GetDefaultApplication") )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIPDM->GetDefaultApplication( &ppda );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self,hr);
	return PyCom_PyObjectFromIUnknown(ppda, IID_IDebugApplication, FALSE);
}

// @pymethod |PyIProcessDebugManager|AddApplication|Description of AddApplication.
PyObject *PyIProcessDebugManager::AddApplication(PyObject *self, PyObject *args)
{
	IProcessDebugManager *pIPDM = GetI(self);
	if ( pIPDM == NULL )
		return NULL;
	// @pyparm <o PyIDebugApplication>|pda||Description for pda
	PyObject *obpda;
	IDebugApplication *pda;
	DWORD pdwAppCookie;
	if ( !PyArg_ParseTuple(args, "O:AddApplication", &obpda) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_InterfaceFromPyInstanceOrObject(obpda, IID_IDebugApplication, (void **)&pda, FALSE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIPDM->AddApplication( pda, &pdwAppCookie );
	pda->Release();
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self,hr);

	PyObject *pyretval = Py_BuildValue("i", pdwAppCookie);
	return pyretval;
}

// @pymethod |PyIProcessDebugManager|RemoveApplication|Description of RemoveApplication.
PyObject *PyIProcessDebugManager::RemoveApplication(PyObject *self, PyObject *args)
{
	IProcessDebugManager *pIPDM = GetI(self);
	if ( pIPDM == NULL )
		return NULL;
	// @pyparm int|dwAppCookie||Description for dwAppCookie
	DWORD dwAppCookie;
	if ( !PyArg_ParseTuple(args, "i:RemoveApplication", &dwAppCookie) )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIPDM->RemoveApplication( dwAppCookie );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self,hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIProcessDebugManager|CreateDebugDocumentHelper|Description of CreateDebugDocumentHelper.
PyObject *PyIProcessDebugManager::CreateDebugDocumentHelper(PyObject *self, PyObject *args)
{
	IProcessDebugManager *pIPDM = GetI(self);
	if ( pIPDM == NULL )
		return NULL;
	// @pyparm <o PyIIUnknown>|unkOuter||The outer object for aggregation, or (usually!) None
	PyObject *obunk;
	IUnknown *punk;
	if ( !PyArg_ParseTuple(args, "O:CreateDebugDocumentHelper", &obunk) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_InterfaceFromPyInstanceOrObject(obunk, IID_IUnknown, (void **)&punk, TRUE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	IDebugDocumentHelper *pdh;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIPDM->CreateDebugDocumentHelper( punk, &pdh );
	if (punk) punk->Release();
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self,hr);
	return PyCom_PyObjectFromIUnknown(pdh, IID_IDebugDocumentHelper, FALSE /* AddRef? */);
}

// @object PyIProcessDebugManager|Description of the interface
static struct PyMethodDef PyIProcessDebugManager_methods[] =
{
	{ "CreateApplication", PyIProcessDebugManager::CreateApplication, 1 }, // @pymeth CreateApplication|Description of CreateApplication
	{ "GetDefaultApplication", PyIProcessDebugManager::GetDefaultApplication, 1 }, // @pymeth GetDefaultApplication|Description of GetDefaultApplication
	{ "AddApplication", PyIProcessDebugManager::AddApplication, 1 }, // @pymeth AddApplication|Description of AddApplication
	{ "RemoveApplication", PyIProcessDebugManager::RemoveApplication, 1 }, // @pymeth RemoveApplication|Description of RemoveApplication
	{ "CreateDebugDocumentHelper", PyIProcessDebugManager::CreateDebugDocumentHelper, 1 }, // @pymeth CreateDebugDocumentHelper|Description of CreateDebugDocumentHelper.
	{ NULL }
};

PyComTypeObject PyIProcessDebugManager::type("PyIProcessDebugManager",
		&PyIUnknown::type,
		sizeof(PyIProcessDebugManager),
		PyIProcessDebugManager_methods,
		GET_PYCOM_CTOR(PyIProcessDebugManager));
// ---------------------------------------------------
//
// Gateway Implementation

STDMETHODIMP PyGProcessDebugManager::CreateApplication(
		/* [out] */ IDebugApplication __RPC_FAR *__RPC_FAR * ppda)
{
	PY_GATEWAY_METHOD;
	if (ppda==NULL) return E_POINTER;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("CreateApplication", &result);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obppda;
	if (!PyArg_Parse(result, "O" , &obppda)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_InterfaceFromPyInstanceOrObject(obppda, IID_IDebugApplication, (void **)ppda, FALSE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGProcessDebugManager::GetDefaultApplication(
		/* [out] */ IDebugApplication __RPC_FAR *__RPC_FAR * ppda)
{
	PY_GATEWAY_METHOD;
	if (ppda==NULL) return E_POINTER;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetDefaultApplication", &result);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obppda;
	if (!PyArg_Parse(result, "O" , &obppda)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_InterfaceFromPyInstanceOrObject(obppda, IID_IDebugApplication, (void **)ppda, FALSE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGProcessDebugManager::AddApplication(
		/* [in] */ IDebugApplication __RPC_FAR * pda,
		/* [out] */ DWORD __RPC_FAR * pdwAppCookie)
{
	PY_GATEWAY_METHOD;
	PyObject *obpda;
	obpda = PyCom_PyObjectFromIUnknown(pda, IID_IDebugApplication, TRUE);
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("AddApplication", &result, "O", obpda);
	Py_XDECREF(obpda);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	if (!PyArg_Parse(result, "i" , pdwAppCookie)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGProcessDebugManager::RemoveApplication(
		/* [in] */ DWORD dwAppCookie)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("RemoveApplication", NULL, "i", dwAppCookie);
	return hr;
}

STDMETHODIMP PyGProcessDebugManager::CreateDebugDocumentHelper(
		/* [in] */ IUnknown *punkOuter,  
		/* [out] */ IDebugDocumentHelper** pddh)
{
	PY_GATEWAY_METHOD;
	PyObject *obunk;
	obunk = PyCom_PyObjectFromIUnknown(punkOuter, IID_IUnknown, TRUE);
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("CreateDebugDocumentHelper", &result, "O", obunk);
	Py_XDECREF(obunk);
	if (FAILED(hr)) return hr;
	PyObject *obret;
	if (!PyArg_Parse(result, "O" , &obret)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_InterfaceFromPyInstanceOrObject(obret, IID_IDebugDocumentHelper, (void **)pddh, FALSE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}
