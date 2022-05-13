# UofSC workspace



## Codes

# V1 
1. Just connecting the dots

# V2.1
1. Trying to implement TDA using a non-linear Algebra approach. 
1. pointInside taken from https://github.com/sasamil/PointInPolygon_Py

# V2.2
1. loop v2 to get the barcode plot
1. on the data taken from the smith paper

# V2.3
1. plots the bar plot and connects line for Mackey glass data

# V3.1
1. Trying to build a function that tracks the number of 1-simplexs over a time-series signal. 
1. Start out on the high-rate data from the air force. 
 
# V3.2
1. run a window over the Air Force data

# V4.1 
1. A copy of V3.1, but uses the combinatorial computational approach rather then the polygram method.

# V4.2
1. builds a plot line by line, looking for the persistence

# V5.1 
1. Gave up on writing my own code, looking at scikit-TDA and Risper
1. https://github.com/scikit-tda/ripser.py

# V5.2 
1. Using example codes I got from https://persim.scikit-tda.org/en/latest/notebooks/Persistence%20images.html to map out persistence images. 

# V5.3. 
1. Trying to merge what I learned form 5.2 and merge that into 5.1.

# V5.4. 
1. Copy of 5.3, but in a loop so save all the images to find one that looks cool

# V5.4.1 
1. Copy of V5.4, but in a loop with set axis (ax) sizes for the figure.  

# 5.5   
1. A copy of 5.3, but no plotting and just looking at timing. 


# 6.1   
1. A copy of 5.3, but trying to add more dimensions to the problem.
1. This is sed up to just give the timing for ripser to the console. 
1. This as 2 embedded dimensions. So it returms H_0, H_1, and H_2. 

# 6.2
1. A copy of 5.5
1. added maxdim to "tda_results = ripser.ripser(data,metric='manhattan',maxdim=2)".
1. added a 3rd dimension to the dataset.

# 6.3
1. Copy of 6.1
1. Added a 3rd dimension. 
























