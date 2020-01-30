import math 

def classifyAPoint(points,p,k=3): 
	distance=[] 
	for group in points: 
		for feature in points[group]: 

			euclidean_distance = math.sqrt((feature[0]-p[0])**2 +(feature[1]-p[1])**2) 

			distance.append((euclidean_distance,group)) 

	distance = sorted(distance)[:k] 

	freq1 = 0  
	freq2 = 0  

	for d in distance: 
		if d[1] == 0: 
			freq1 += 1
		elif d[1] == 1: 
			freq2 += 1

	return 0 if freq1>freq2 else 1

 
def main(): 


	points = {0:[(2,4),(4,2),(6,4),(4,6)], 
			1:[(4,4),(6,2)]} 

	p = (6,6) 

	k = 3

	print("The value classified to unknown point is: {} \n"  .format(classifyAPoint(points,p,k)))

if __name__ == '__main__': 
	main() 
