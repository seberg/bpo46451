#include <Python.h>


static PyObject *pyfunc;
static PyObject *kwnames;

static PyObject *
method(PyObject *mod, PyObject *arg, PyObject *unused)
{
    return PyObject_VectorcallDict(pyfunc, &arg, 1, NULL);
}



static struct PyMethodDef test_methods[] = {
    {"method",
        (PyCFunction)method,
        METH_O, NULL},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "test",
        NULL,
        -1,
        test_methods,
        NULL,
        NULL,
        NULL,
        NULL
};


PyMODINIT_FUNC PyInit_test(void) {
    PyObject *m = PyModule_Create(&moduledef);
    if (m == NULL) {
        return NULL;
    }
    
    PyObject *pymod = PyImport_ImportModule("bpo46451.mod");
    if (pymod == NULL) {
        Py_DECREF(m);
        return NULL;
    }
    pyfunc = PyObject_GetAttrString(pymod, "function");
    Py_DECREF(pymod);
    if (pyfunc == NULL) {
        Py_DECREF(m);
        return NULL;
    }
    kwnames = Py_BuildValue("()");
    if (kwnames == NULL) {
        Py_DECREF(pyfunc);
        Py_DECREF(m);
        return NULL;
    }
    
    return m;
}

