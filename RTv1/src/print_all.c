#include "rtv1.h"

void print_all(t_obj *obj, t_obj *light)
{
	t_cone	*cone;
	t_cylinder *cylinder;
	t_light	*light_;
	t_plane	*plane;
	t_sphere	*sphere;

	while (obj->next)
	{
		if (obj->type == CONE)
		{
			cone = (t_cone *)obj->shape;
			printf("cone : %f,%f,%f : %f,%f,%f : %f : %d\n",
				cone->vertex[0], cone->vertex[1], cone->vertex[0],
					cone->axis[0], cone->axis[1], cone->axis[2],
						cone->angle, obj->clr);
		}
		if (obj->type == CYLINDER)
		{
			cylinder = (t_cylinder *)obj->shape;
			printf("cylinder : %f,%f,%f : %f,%f,%f : %f : %d\n",
				cylinder->start[0],cylinder->start[1], cylinder->start[2],
					cylinder->axis[0], cylinder->axis[1], cylinder->axis[2],
					cylinder->radius, obj->clr);
		}
		if (obj->type == PLANE)
		{
			plane = (t_plane *)obj->shape;
			printf("plane : %f,%f,%f : %f,%f,%f : %d\n",
				plane->dot[0], plane->dot[1], plane->dot[2],
					plane->normal[0], plane->normal[1], plane->normal[2], obj->clr);
		}
		if (obj->type == SPHERE)
		{
			sphere = (t_sphere *)obj->shape;
			printf("sphere : %f,%f,%f : %f : %d\n",
				sphere->center[0], sphere->center[1], sphere->center[2],
					sphere->radius, obj->clr);
		}
		obj = obj->next;
	}
	if (obj->type == CONE)
	{
		cone = (t_cone *)obj->shape;
		printf("cone : %f,%f,%f : %f,%f,%f : %f : %d\n",
			cone->vertex[0], cone->vertex[1], cone->vertex[0],
				cone->axis[0], cone->axis[1], cone->axis[2],
					cone->angle, obj->clr);
	}
	if (obj->type == CYLINDER)
	{
		cylinder = (t_cylinder *)obj->shape;
		printf("cylinder : %f,%f,%f : %f,%f,%f : %f : %d\n",
			cylinder->start[0], cylinder->start[1], cylinder->start[2],
				cylinder->axis[0], cylinder->axis[1], cylinder->axis[2],
				cylinder->radius, obj->clr);
	}
	if (obj->type == PLANE)
	{
		plane = (t_plane *)obj->shape;
		printf("plane : %f,%f,%f : %f,%f,%f : %d\n",
			plane->dot[0], plane->dot[1], plane->dot[2],
				plane->normal[0], plane->dot[1], plane->dot[2], obj->clr);
	}
	if (obj->type == SPHERE)
	{
		sphere = (t_sphere *)obj->shape;
		printf("sphere : %f,%f,%f : %f : %d\n",
			sphere->center[0], sphere->center[1], sphere->center[2],
				sphere->radius, obj->clr);
	}
	while (light->next)
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
