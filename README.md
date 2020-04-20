# factpy
Python package "factpy" calculates the factorial of a large integer, which may be much greater than the maximum memory of any data type. FactSum implements dramatically fast. It takes only 0.45 seconds to cumpute 10000! (it approximates 2.8E+35660), and 0.98 seconds to compute 10000! and sum=1!+2!+3!+...+10000! simultaneously. It takes only one minute to cumpute 100000! (it approximates 2.8E+456574), and less then two minutes to compute 100000! and sum=1!+2!+3!+...+100000! simultaneously.

# Installation

    pip install git+https://github.com/xliusufe/factpy.git

# Usage
- Syntax: `fact(n,is_sums)`
    - Input:
        - `n`: a natural number 
        - `is_sums`: logical indicating that fact calculates the sum of factorials from 1 to n (`factsums` = 1!+2!+3!+...). `factsums` is calcuated if `is_sums=True` or `is_sums=1`, do not otherwise. The default is `False`.

    - Output is a dictionary with keys:
        - `facts`: the factorial of n. It is a string.
        - `factsums`: the sum of factorials from 1 to n if `is_sum` is True.
        - `len_fact`: the length of the factorial.
        - `nzeros`: the number of zeros in the factorial.


   
- [x] [factorial.md](https://github.com/xliusufe/FactSum/blob/master/inst/factorial.md) -------------------- The factorial of n=20, 50, 100, 1000, 10000, and 100000.

- [x] [Web-based calculator](https://xliusufe.shinyapps.io/factorial/) --------- A web-based calculator 

- An R package named [FactSum](https://github.com/xliusufe/FactSum/) can be found on github.
   
# Example 1

    from fact import fact

    fit = fact(10)
    # fit = fact(10,0)
    # fit = fact(10,False)

    print(fit['facts'])
    print(fit['len_fact'])
    print(fit['nzeros'])
    #------------------------

    fit = fact(10,1)
    # fit = fact(10,True)

    print(fit['facts'])
    print(fit['factsums'])
    print(fit['len_fact'])
    print(fit['nzeros'])

# Example 2
    import fact as fs

    fit <- fs.fact(10)

    fit = fact(10)
    # fit = fact(10,0)
    # fit = fact(10,False)

    print(fit['facts'])
    print(fit['len_fact'])
    print(fit['nzeros'])
    #------------------------

    fit = fact(10,1)
    # fit = fact(10,True)

    print(fit['facts'])
    print(fit['factsums'])
    print(fit['len_fact'])
    print(fit['nzeros'])
    

# Development
This Python package is developed by Xu Liu (liu.xu@sufe.edu.cn).

