// This file declares the IObjectWithSite Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIObjectWithSite : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR(PyIObjectWithSite);
	static IObjectWithSite *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *SetSite(PyObject *self, PyObject *args);
	static PyObject *GetSite(PyObject *self, PyObject *args);

protected:
	PyIObjectWithSite(IUnknown *pdisp);
	~PyIObjectWithSite();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGObjectWithSite : public PyGatewayBase, public IObjectWithSite
{
protected:
	PyGObjectWithSite(PyObject *instance) : PyGatewayBase(instance) { ; }
	PYGATEWAY_MAKE_SUPPORT2(PyGObjectWithSite, IObjectWithSite, IID_IObjectWithSite, PyGatewayBase)



	// IObjectWithSite
	STDMETHOD(SetSite)(
		IUnknown * pUnkSite);

	STDMETHOD(GetSite)(
		REFIID riid,
		void ** ppvSite);

};
