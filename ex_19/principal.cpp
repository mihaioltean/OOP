#include <stdio.h>

#include "controller.h"

int main(void)
{
	t_eq2_view eq2_view;
	t_eq2_model eq2_model;
	t_eq2_controller eq2_controller(&eq2_model, &eq2_view);

	eq2_controller.read_eq2_coeficients();
	eq2_controller.solve();

	getchar();
}