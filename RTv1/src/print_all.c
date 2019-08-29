#include "rtv1.h"

void print_all(t_obj *obj, t_obj *light)
{
	t_cone	*cone;
	t_cylinder *cylinder;
	t_light	*light_;
	t_plane	*plane;
	t_sphere	*sphere;

	while(obj->next)
	{
		if (obj->type == CONE)
		{
			cone = (t_cone *)obj->shape;
			printf("cone : %f,%f,%f : %f,%f,%f : %f : %d\n",
				cone->cone_vertex[0], cone->cone_vertex[1], cone->cone_vertex[0],
					cone->cone_axis[0], cone->cone_axis[1], cone->cone_axis[2],
						cone->cone_angle, obj->clr);
		}
		if (obj->type == CYLINDER)
		{
			cylinder = (t_cylinder *)obj->shape;
			printf("cylinder : %f,%f,%f : %f,%f,%f : %f : %d\n",
				cylinder->cylinder_start[0],cylinder->cylinder_start[1], cylinder->cylinder_start[2],
					cylinder->cylinder_axis[0], cylinder->cylinder_axis[1], cylinder->cylinder_axis[2],
					cylinder->cylinder_radius, obj->clr);
		}
		if (obj->type == PLANE)
		{
			plane = (t_plane *)obj->shape;
			printf("plane : %f,%f,%f : %f,%f,%f : %d\n",
				plane->plane_dot[0], plane->plane_dot[1], plane->plane_dot[2],
					plane->plane_normal[0], plane->plane_normal[1], plane->plane_normal[2], obj->clr);
		}
		if (obj->type == SPHERE)
		{
			sphere = (t_sphere *)obj->shape;
			printf("sphere : %f,%f,%f : %f : %d\n",
				sphere->sphere_center[0], sphere->sphere_center[1], sphere->sphere_center[2],
					sphere->sphere_radius, obj->clr);
		}
		obj = obj->next;
	}
	if (obj->type == CONE)
	{
		cone = (t_cone *)obj->shape;
		printf("cone : %f,%f,%f : %f,%f,%f : %f : %d\n",
			cone->cone_vertex[0], cone->cone_vertex[1], cone->cone_vertex[0],
				cone->cone_axis[0], cone->cone_axis[1], cone->cone_axis[2],
					cone->cone_angle, obj->clr);
	}
	if (obj->type == CYLINDER)
	{
		cylinder = (t_cylinder *)obj->shape;
		printf("cylinder : %f,%f,%f : %f,%f,%f : %f : %d\n",
			cylinder->cylinder_start[0],cylinder->cylinder_start[1], cylinder->cylinder_start[2],
				cylinder->cylinder_axis[0], cylinder->cylinder_axis[1], cylinder->cylinder_axis[2],
				cylinder->cylinder_radius, obj->clr);
	}
	if (obj->type == PLANE)
	{
		plane = (t_plane *)obj->shape;
		printf("plane : %f,%f,%f : %f,%f,%f : %d\n",
			plane->plane_dot[0], plane->plane_dot[1], plane->plane_dot[2],
				plane->plane_normal[0], plane->plane_dot[1], plane->plane_dot[2], obj->clr);
	}
	if (obj->type == SPHERE)
	{
		sphere = (t_sphere *)obj->shape;
		printf("sphere : %f,%f,%f : %f : %d\n",
			sphere->sphere_center[0], sphere->sphere_center[1], sphere->sphere_center[2],
				sphere->sphere_radius, obj->clr);
	}
	while(light->next)
	{
		light_ = light->shape;
		if (!light_->type)
			printf("light %f\n", light_->intensive);
		else if (light_->type == 1)
			printf("light %f, %f %f %f\n", light_->intensive, light_->center[0], light_->center[1], light_->center[2]);
		else if (light_->type == 2)
			printf("light %f, %f %f %f\n", light_->intensive, light_->vector[0], light_->vector[1], light_->vector[2]);
		light = light->next;
	}
	light_ = light->shape;
	if (!light_->type)
		printf("light %f\n", light_->intensive);
	else if (light_->type == 1)
		printf("light %f, %f %f %f\n", light_->intensive, light_->center[0], light_->center[1], light_->center[2]);
	else if (light_->type == 2)
		printf("light %f, %f %f %f\n", light_->intensive, light_->vector[0], light_->vector[1], light_->vector[2]);

}
