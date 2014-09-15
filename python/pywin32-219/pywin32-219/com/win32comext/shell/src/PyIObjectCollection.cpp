// This file implements the IObjectCollection Interface for Python.
// Generated by makegw.py

#include "shell_pch.h"

// Requires Windows 7 SDK to build
#if WINVER >= 0x0601

#include "PyIObjectArray.h"
#include "PyIObjectCollection.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIObjectCollection::PyIObjectCollection(IUnknown *pdisp):
	PyIObjectArray(pdisp)
{
	ob_type = &type;
}

PyIObjectCollection::~PyIObjectCollection()
{
}

/* static */ IObjectCollection *PyIObjectCollection::GetI(PyObject *self)
{
	return (IObjectCollection *)PyIObjectArray::GetI(self);
}

// @pymethod |PyIObjectCollection|AddObject|Adds a single object to the collection
PyObject *PyIObjectCollection::AddObject(PyObject *self, PyObject *args)
{
	IObjectCollection *pIOC = GetI(self);
	if ( pIOC == NULL )
		return NULL;
	IUnknown *punk;
	PyObject *obpunk;
	// @pyparm <o PyIUnknown>|punk||Object to be added
	if ( !PyArg_ParseTuple(args, "O:AddObject", &obpunk) )
		return NULL;
	if (!PyCom_InterfaceFromPyObject(obpunk, IID_IUnknown, (void **)&punk, FALSE))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIOC->AddObject( punk );
	punk->Release();
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIOC, IID_IObjectCollection );
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIObjectCollection|AddFromArray|Adds a number of objects contained in an <o PyIObjectArray> collection
PyObject *PyIObjectCollection::AddFromArray(PyObject *self, PyObject *args)
{
	IObjectCollection *pIOC = GetI(self);
	if ( pIOC == NULL )
		return NULL;
	IObjectArray *Source;
	PyObject *obSource;
	// @pyparm <o PyIObjectArray>|Source||Objects to be added to the collection
	if ( !PyArg_ParseTuple(args, "O:AddFromArray", &obSource))
		return NULL;
	if (!PyCom_InterfaceFromPyObject(obSource, IID_IObjectArray, (void **)&Source, FALSE))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIOC->AddFromArray(Source);
	Source->Release();
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIOC, IID_IObjectCollection );
	Py_INCREF(Py_None);
	return Py_None;
}

// @pymethod |PyIObjectCollection|RemoveObjectAt|Removes a single object from the collection
PyObject *PyIObjectCollection::RemoveObjectAt(PyObject *self, PyObject *args)
{
	IObjectCollection *pIOC = GetI(self);
	if ( pIOC == NULL )
		return NULL;
	// @pyparm int|Index||Zero-based index of item to remove
	UINT Index;
	if ( !PyArg_ParseTuple(args, "i:RemoveObjectAt", &Index) )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIOC->RemoveObjectAt( Index );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIOC, IID_IObjectCollection );
	Py_INCREF(Py_None);
	return Py_None;
}

// @pymethod |PyIObjectCollection|Clear|Empties the container.
PyObject *PyIObjectCollection::Clear(PyObject *self, PyObject *args)
{
	IObjectCollection *pIOC = GetI(self);
	if ( pIOC == NULL )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIOC->Clear( );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIOC, IID_IObjectCollection );
	Py_INCREF(Py_None);
	return Py_None;
}

// @object PyIObjectCollection|Modifiable container for a number of IUnknown objects
static struct PyMethodDef PyIObjectCollection_methods[] =
{
	{ "AddObject", PyIObjectCollection::AddObject, 1 }, // @pymeth AddObject|Adds a single object to the collection
	{ "AddFromArray", PyIObjectCollection::AddFromArray, 1 }, // @pymeth AddFromArray|Adds a number of objects contained in an <o PyIObjectArray> collection
	{ "RemoveObjectAt", PyIObjectCollection::RemoveObjectAt, 1 }, // @pymeth RemoveObjectAt|Removes a single object from the collection
	{ "Clear", PyIObjectCollection::Clear, METH_NOARGS }, // @pymeth Clear|Empties the container
	{ NULL }
};

PyComTypeObject PyIObjectCollection::type("PyIObjectCollection",
		&PyIObjectArray::type,		 // @base PyIObjectCollection|PyIObjectArray
		sizeof(PyIObjectCollection),
		PyIObjectCollection_methods,
		GET_PYCOM_CTOR(PyIObjectCollection));

#endif // WINVER
