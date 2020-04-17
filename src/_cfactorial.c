#include <Python.h>
#include "cfactorial.h"
#include <numpy/arrayobject.h>
#include <stdlib.h>
#include <stdio.h>

static PyObject *py_factorial(PyObject *self, PyObject *args) {
    
    int *number_n;
    int *is_sum;

    if (!PyArg_ParseTuple(args,"OOdi", &number_n,&is_sum)) {
        return NULL;
    }


    // Create a numpy array and return it.
    int i,L, Ln=1;
    i = number_n;
    while(i/10){i = i/10; Ln++;	}
    L=(Ln-1+i*0.5)*n;
    char *fact = (char *)malloc(sizeof(char)*L);
    int *len1 = (int *)malloc(sizeof(int)*5);

    // Call the external C function.
    if(is_sum){
        factorial(number_n, fact, len1);
        npy_intp dims[1] = {L};
        PyObject *ret = PyArray_SimpleNewFromData(1, dims, NPY_STRING, fact);

        npy_intp dims[1] = {5};
        PyObject *ret_len = PyArray_SimpleNewFromData(1, dims, NPY_INT, len1);

        // Clean up. 
        Py_DECREF(py_fact_array);
        Py_DECREF(py_len1_array);   
        return ret,ret_len;
    } 
    else{
        L += 2;
        char *factsum = (char *)malloc(sizeof(char)*L);
        factorial(number_n, fact, factsum, len1);

        npy_intp dims[1] = {L};
        PyObject *ret = PyArray_SimpleNewFromData(1, dims, NPY_STRING, fact);
        PyObject *ret_sum = PyArray_SimpleNewFromData(1, dims, NPY_STRING, factsum);

        npy_intp dims[1] = {5};
        PyObject *ret_len = PyArray_SimpleNewFromData(1, dims, NPY_INT, len1);

        // Clean up. 
        Py_DECREF(py_fact_array);
        Py_DECREF(py_factsum_array);
        Py_DECREF(py_len1_array);

        return ret,ret_sum,ret_len;
    }
}

/* Documentations */
static char module_docs[] = "Calculates the factorial of a large integer, which may be much greater than the maximum memory of any data type.";

static char cfunction_docs[] = "Some thing about your C function.";

/* Module method table */
static PyMethodDef MydemoMethods[] = {
  {"factorial",  py_factorial, METH_VARARGS, cfunction_docs},
  /* If your extension module has many export functions, you need write interfaces for each of them. */
  /* And then add them to Module method table. For example: */
  /* {"mycfunc2",  py_mycfunc2, METH_VARARGS, cfunction2_docs}, */
  { NULL, NULL, 0, NULL}
};

/* Module structure */
static struct PyModuleDef demomodule = {
    PyModuleDef_HEAD_INIT,
    "factsumpy",           /* name of module */
    module_docs,        /* Doc string (may be NULL) */
    -1,                 /* Size of per-interpreter state or -1 */
    MydemoMethods       /* Method table */
};

/* Module initialization function */
PyMODINIT_FUNC PyInit_Demo(void) {
    PyObject *object = PyModule_Create(&demomodule);
    if(object == NULL) {
        return NULL;
    }
    import_array();
    return object;
}