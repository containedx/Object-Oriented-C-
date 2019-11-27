# STL PERFORMANCE ANALYSIS


###### assigned containers: vector, map, unordered_multiset 

I have measured performance of methods in mentioned above containers. 
My results are listed below. 
Raw output is avaiable in directory 'output'.

Hardware: 
4xintelcorei5
10GB RAM

expected results come from cppreference.com. 
Most of my results are compatibile with them. 
Plots show some noises, which may be affected by small range.

Running benchmarks in Release showed definitely shorter times of evaluated functions.  
I used 'escape functions' to prevent values or expressions from being optimized away.
DoNotOptimize() forces value to be stored  and ClobberMemory() forces to perform all pending writes to memory.

## MAP

`at`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_at.png)  
 ![](output/PLOTS/RELEASE_map_at.png)

 
`operator[]`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_operator.png)
  ![](output/PLOTS/RELEASE_map_operator.png)

`empty`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_empty.png)
  ![](output/PLOTS/RELEASE_map_empty.png)

`size`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_size.png)
  ![](output/PLOTS/RELEASE_map_size.png)

`max_size`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_maxsize.png)
  ![](output/PLOTS/RELEASE_map_maxsize.png)

`clear`

expected: O(n)

my result: O(lgN)

 ![](output/PLOTS/map_clear.png)
  ![](output/PLOTS/RELEASE_map_clear.png)

`insert`

expected: lgN / amortized O(1)

my result: O(1)

 ![](output/PLOTS/map_insert.png)
  ![](output/PLOTS/RELEASE_map_insert.png)

`erase`

expected: amortized constant/ log(size)

my result: O(1)

 ![](output/PLOTS/map_erase.png)
  ![](output/PLOTS/RELEASE_map_erase.png)

`swap`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_swap.png)
  ![](output/PLOTS/RELEASE_map_swap.png)

`count`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_count.png)
  ![](output/PLOTS/RELEASE_map_count.png)

`find`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_find.png)
  ![](output/PLOTS/RELEASE_map_find.png)

`equal_range`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_equalrange.png)
  ![](output/PLOTS/RELEASE_map_equalrange.png)

`lower_bound`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_lowerbound.png)
  ![](output/PLOTS/RELEASE_map_lowerbound.png)
 
`upper_bound`

expected: O(lgN)

my results: O(lgN)

 ![](output/PLOTS/map_upperbound.png)
  ![](output/PLOTS/RELEASE_map_upperbound.png)


## VECTOR

`at` 

expected: O(1)

my results: O(1)

![](output/PLOTS/vector_at.png)
![](output/PLOTS/RELEASE_vector_at.png)

`operator[]`

expected: O(1)

my results: O(1)

![](output/PLOTS/vector_operator.png)
![](output/PLOTS/RELEASE_vector_operator.png)

`front`

expected: O(1)

my results: O(1)

![](output/PLOTS/vector_front.png)
![](output/PLOTS/RELEASE_vector_front.png)

`back`

expected: O(1)

my results: O(1)

![](output/PLOTS/vector_back.png)
![](output/PLOTS/RELEASE_vector_back.png)

`empty`

expected: O(1)

my results: O(1)

![](output/PLOTS/vector_empty.png)
![](output/PLOTS/RELEASE_vector_empty.png)

`size`

expected: O(1)

my results: O(1)

![](output/PLOTS/vector_size.png)
![](output/PLOTS/RELEASE_vector_size.png)

`max_size`

expected: O(1)

my results: O(1)

![](output/PLOTS/vector_maxsize.png)
![](output/PLOTS/RELEASE_vector_maxsize.png)

`shrink_to_fit`

expected:  O(n)

my results: O(1)

![](output/PLOTS/vector_shrink.png)
![](output/PLOTS/RELEASE_vector_shrink.png)

`clear`

expected: O(n)

my results: O(1)

![](output/PLOTS/vector_clear.png)
![](output/PLOTS/RELEASE_vector_clear.png)

`insert`

expected: O(n)

my results: O(1)

![](output/PLOTS/vector_insert.png)
![](output/PLOTS/RELEASE_vector_insert.png)

`erase`

expected: O(n)

my results: O(1)

![](output/PLOTS/vector_erase.png)
![](output/PLOTS/RELEASE_vector_erase.png)

`push_back`

expected: amortized constant

my results: O(1)

![](output/PLOTS/vector_pushback.png)
![](output/PLOTS/RELEASE_vector_pushback.png)

`pop_back`

expected: O(1)

my results: O(1)

![](output/PLOTS/vector_popback.png)
![](output/PLOTS/RELEASE_vector_popback.png)

`resize`

expected: O(n)

my results: O(1)

![](output/PLOTS/vector_resize.png)
![](output/PLOTS/RELEASE_vector_resize.png)

`swap`

expected: O(1)

my results: O(1)

![](output/PLOTS/vector_swap.png)
![](output/PLOTS/RELEASE_vector_swap.png)



## UNORDERED MULTISET

`empty`

expected: O(1)

my results: O(1)

![](output/PLOTS/unorderedmultiset_empty.png)
![](output/PLOTS/RELEASE_unorderedmultiset_empty.png)

`size`

expected: O(1)

my results: O(1)

![](output/PLOTS/unorderedmultiset_size.png)
![](output/PLOTS/RELEASE_unorderedmultiset_size.png)


`max_size`

expected: O(1)

my results: O(1)

![](output/PLOTS/unorderedmultiset_maxsize.png)
![](output/PLOTS/RELEASE_unorderedmultiset_maxsize.png)


`clear`

expected: O(n)

my results: O(n)

![](output/PLOTS/unorderedmultiset_clear.png)
![](output/PLOTS/RELEASE_unorderedmultiset_clear.png)


`insert`

expected: O(1) 

my results: O(1)

![](output/PLOTS/unorderedmultiset_insert.png)
![](output/PLOTS/RELEASE_unorderedmultiset_insert.png)


`erase`

expected: O(1)

my results: O(1)

![](output/PLOTS/unorderedmultiset_erase.png)
![](output/PLOTS/RELEASE_unorderedmultiset_erase.png)


`swap`

expected: O(1)

my results: O(1)

![](output/PLOTS/unorderedmultiset_swap.png)
![](output/PLOTS/RELEASE_unorderedmultiset_swap.png)


`count`

expected:  O(n)

my results: O(n)

![](output/PLOTS/unorderedmultiset_count.png)
![](output/PLOTS/RELEASE_unorderedmultiset_count.png)


`find`

expected: O(1) at worst linear

my results: O(1)

![](output/PLOTS/unorderedmultiset_find.png)
![](output/PLOTS/RELEASE_unorderedmultiset_find.png)


`equal_range`

expected: linear O(n)

my results: O(1)

![](output/PLOTS/unorderedmultiset_equalrange.png)
![](output/PLOTS/RELEASE_unorderedmultiset_equalrange.png)


`rehash`

expected: O(n) worst ^2

my results: O(1)

![](output/PLOTS/unorderedmultiset_rehash.png)
![](output/PLOTS/RELEASE_unorderedmultiset_rehash.png)


`reserve`

expected: O(n)

my results: O(1)

![](output/PLOTS/unorderedmultiset_reserve.png)
![](output/PLOTS/RELEASE_unorderedmultiset_reserve.png)








