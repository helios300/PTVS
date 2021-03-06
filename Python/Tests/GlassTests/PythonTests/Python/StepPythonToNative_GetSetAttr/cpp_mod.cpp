#pragma optimize("", off)
#include <python.h>

struct CppObj {
    PyObject_HEAD
};

PyObject* CppObj_getattr(PyObject* self, char* attr_name) {
    Py_RETURN_NONE;
}

int CppObj_setattr(PyObject* self, char* attr_name, PyObject* value) {
    return 0;
}

PyTypeObject* CppObj_type() {
    static PyTypeObject t = { PyVarObject_HEAD_INIT(NULL, 0) };
    t.tp_name = "cpp_mod.CppObj";
    t.tp_basicsize = sizeof CppObj;
    t.tp_flags = Py_TPFLAGS_DEFAULT;
    t.tp_getattr = CppObj_getattr;
    t.tp_setattr = CppObj_setattr;
    return &t;
}

PyMethodDef methods[] = { NULL };

PyTypeObject* types[] = {
    CppObj_type(),
    NULL
};
