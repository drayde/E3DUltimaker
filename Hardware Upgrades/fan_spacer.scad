
// height in mm
height = 23;

// inner diameter in mm
inner_diameter = 1.75*2;

// outer diameter in mm
outer_diameter = 3.2*2;

// inner chamfer at bottom in mm (to avoid 'elephant foot' when 3d printing)
chamfer_inner = 0.4;

// inner chamfer at bottom in mm (to avoid 'elephant foot' when 3d printing)
chamfer_outer = 0.0;

/* [Hidden] */

inner_radius = inner_diameter/2;
outer_radius = outer_diameter/2;
eps = 0.001;

$fn = 50;

difference() 
{
	cylinder(h=height, r=outer_radius);
	translate([0,0,-eps]) cylinder(h=height+1, r=inner_radius);

	translate([0,0,-eps]) cylinder(h=chamfer_inner, r1=inner_radius+chamfer_inner, r2=inner_radius);
    
    translate([0,0,-eps]) difference()
    {
        cylinder(h=chamfer_outer, r=outer_radius);
        translate([0,0,-eps]) cylinder(h=chamfer_outer, r1=outer_radius-chamfer_outer, r2=outer_radius+eps);
    }
}



