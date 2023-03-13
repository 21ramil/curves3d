# curves
1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified 
definitions are below). Each curve should be able to return a 3D point and a first derivative (3D 
vector) per parameter t along the curve.
2. Populate a container (e.g. vector or list) of objects of these types created in random manner with 
random parameters.
3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
4. Populate a second container that would contain only circles from the first container. Make sure the
second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the 
smallest radius, the last - the greatest.
6. Compute the total sum of radii of all curves in the second container.

Curve definitions:
- All curves are parametrically defined, i.e. a point is calculated using some C(t) formula.
- Circle is planar in the plane XoY (i.e. all Z-coordinates are 0) and is defined by its radius.
- Ellipse is planar in the plane XoY and is defined by its two radii, along X and Y axes.
- Helix is spatial and is defined by its radius and step (see the figure below). It takes 2 * PI in 
parametric space to make a round, i.e. any point on helix satisfies the condition C(t + 2*PI) = C(t) + 
{0, 0, step}


![image](https://user-images.githubusercontent.com/72577760/224327990-a8af23ee-83fe-430a-b7ef-c04beea6ecf6.png)
