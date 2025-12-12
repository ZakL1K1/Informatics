#include <Python.h>
#include <ctime>

static PyObject* subtract_arrays(PyObject* self, PyObject* args) {
    PyObject* list1, * list2;
    if (!PyArg_ParseTuple(args, "OO", &list1, &list2)) {
        return NULL;
    }

    Py_ssize_t len1 = PyList_Size(list1);

    clock_t start_time = clock();

    PyObject* result = PyList_New(len1);
    for (Py_ssize_t i = 0; i < len1; ++i) {
        PyObject* item1 = PyList_GetItem(list1, i);
        PyObject* item2 = PyList_GetItem(list2, i);
        long val1 = PyLong_AsLong(item1);
        long val2 = PyLong_AsLong(item2);
        PyObject* diff = PyLong_FromLong(val1 - val2);
        PyList_SetItem(result, i, diff);
    }

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    PyObject* time_obj = PyFloat_FromDouble(time_taken);
    PyObject* tuple = PyTuple_Pack(2, result, time_obj);
    Py_DECREF(result);
    Py_DECREF(time_obj);

    return tuple;
}

static PyMethodDef SubtractMethods[] = {
    {"subtract", subtract_arrays, METH_VARARGS, "¬ычитает два массива целых чисел и возвращает результат и врем€ выполнени€."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef subtractmodule = {
    PyModuleDef_HEAD_INIT,
    "subtract_arrays",
    NULL,
    -1,
    SubtractMethods
};

PyMODINIT_FUNC PyInit_subtract_arrays(void) {
    return PyModule_Create(&subtractmodule);
}