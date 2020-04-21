from ._FACTPY import CFACTORIAL_, CFACTORIAL_SUM_


def fact(n,is_sums=False):
    if(n<0):
        return "n must be nonnegative integer!"
    if n==0:
        return 1        
    else:  
        if is_sums==True or is_sums:      
            fact0 = CFACTORIAL_SUM_(n)
            fact1 = {'facts': bytes.decode(fact0['fact'][0]), 'factsums': bytes.decode(fact0['fact_sum'][0]),  
                        'len_fact':fact0['fact_len'][0],'nzeros':fact0['fact_len'][3]}         
        else:
            fact0 = CFACTORIAL_(n)
            fact1 = {'facts': bytes.decode(fact0['fact'][0]),
                        'len_fact':fact0['fact_len'][0],'nzeros':fact0['fact_len'][3]}
    
    return fact1