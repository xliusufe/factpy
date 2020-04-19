#include <Python.h>
#include "cfactorial.h"
#include <numpy/arrayobject.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static PyObject *py_CFACTORIAL_(PyObject *self, PyObject *args) {    
    int number_n;

    if(!PyArg_ParseTuple(args,"i", &number_n)){
        return NULL;
    }

    // Create a numpy array and return it.
    int i,L, Ln=1;
    i = number_n;
    while(i/10){i = i/10; Ln++;	}
    L=(Ln-1+(int)(i*0.5))*number_n;
    char *fact = (char *)malloc(sizeof(char)*L);
    int *len1 = (int *)malloc(sizeof(int)*5);

    // Call the external C function.
    _CFACTORIAL(number_n, fact, len1);

    npy_intp dims[1] = {1};
    PyObject *ret = PyArray_New(&PyArray_Type, 1, dims, NPY_STRING, NULL, fact, (int)strlen(fact), NPY_ARRAY_OWNDATA, NULL);

    npy_intp dims1[1] = {5};
    PyObject *ret_len = PyArray_SimpleNewFromData(1, dims1, NPY_INT, len1);

    return Py_BuildValue("{s:O,s:O}", "fact", ret, "fact_len", ret_len);
}

static PyObject *py_CFACTORIAL_SUM_(PyObject *self, PyObject *args) {    
    int number_n;

    if (!PyArg_ParseTuple(args,"i", &number_n)) {
        return NULL;
    }


    // Create a numpy array and return it.
    int i,L, Ln=1;
    i = number_n;
    while(i/10){i = i/10; Ln++;	}
    L = (Ln-1+(int)(i*0.5))*number_n;
    char *fact = (char *)malloc(sizeof(char)*L);
    int *len1 = (int *)malloc(sizeof(int)*5);

    // Call the external C function.
    char *factsum = (char *)malloc(sizeof(char)*(L+2));
    _CFACTORIAL_SUM(number_n, fact, factsum, len1);

    npy_intp dims[1] = {1};
    PyObject *ret = PyArray_New(&PyArray_Type, 1, dims, NPY_STRING, NULL, fact, (int)strlen(fact), NPY_ARRAY_OWNDATA, NULL);
    PyObject *ret_sum = PyArray_New(&PyArray_Type, 1, dims, NPY_STRING, NULL, factsum, (int)strlen(factsum), NPY_ARRAY_OWNDATA, NULL);

    npy_intp dims1[1] = {5};
    PyObject *ret_len = PyArray_SimpleNewFromData(1, dims1, NPY_INT, len1);    
    return Py_BuildValue("{s:O,s:O,s:O}", "fact", ret, "fact_sum", ret_sum, "fact_len", ret_len);    
}

/* Documentations */
static char module_docs[] = "Calculates the factorial of a large integer, which may be much greater than the maximum memory of any data type.";

static char cfunction_docs[] = "Calculates the factorial of a large integer. Output a dictionary with 'fact', and 'fact_len', where 'fact' saves the factorial of integer 'n', and 'fact_len' saves the length and number of zeros of the factorial.";

static char cfunction_sum_docs[] = "Calculates the factorial of a large integer. Output a dictionary with 'fact', 'fact_sum', and 'fact_len', were 'fact' saves the factorial of integer 'n', 'fact_sum' saves the sum of factorials from 1 to 'n', and 'fact_len' saves the length and number of zeros of the factorial.";

/* Module method table */
static PyMethodDef MydemoMethods[] = {// "CFACTORIAL_" in py_CFACTORIAL_ must be exactly same as the output function "CFACTORIAL_"
  {"CFACTORIAL_",  py_CFACTORIAL_, METH_VARARGS, cfunction_docs},
  {"CFACTORIAL_SUM_",  py_CFACTORIAL_SUM_, METH_VARARGS, cfunction_sum_docs},
  /* If your extension module has many export functions, you need write interfaces for each of them. */
  /* And then add them to Module method table. For example: */
  /* {"mycfunc2",  py_mycfunc2, METH_VARARGS, cfunction2_docs}, */
  { NULL, NULL, 0, NULL}
};

/* Module structure */
static struct PyModuleDef factpymodule = {
    PyModuleDef_HEAD_INIT,
    "_factpy",           /* name of module */
    module_docs,        /* Doc string (may be NULL) */
    -1,                 /* Size of per-interpreter state or -1 */
    MydemoMethods       /* Method table */
};

/* Module initialization function */
PyMODINIT_FUNC PyInit__factpy(void) {
    PyObject *object = PyModule_Create(&factpymodule);
    if(object == NULL) {
        return NULL;
    }
    import_array();
    return object;
}