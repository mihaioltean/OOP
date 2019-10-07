#include "controller.h"

//---------------------------------------------------------------------
t_eq2_controller::t_eq2_controller(t_eq2_model* eq2_model, t_eq2_view* eq2_view)
{
	this->eq2_model = eq2_model;
	this->eq2_view = eq2_view;
	this->eq2_model->set_observer(this);
}
//---------------------------------------------------------------------
void t_eq2_controller::read_eq2_coeficients(void)
{
	eq2_model->set_a(eq2_view->read_a());
	eq2_model->set_b(eq2_view->read_b());
	eq2_model->set_c(eq2_view->read_c());
}
//---------------------------------------------------------------------
void t_eq2_controller::solve(void)
{
	eq2_model->solve();
}
//---------------------------------------------------------------------
void t_eq2_controller::print_solutions(void)
{
	eq2_view->print_solutions(eq2_model->get_x1_re(), eq2_model->get_x1_im(), eq2_model->get_x2_re(), eq2_model->get_x2_im());
}
//---------------------------------------------------------------------
void t_eq2_controller::notify(void)
{
	print_solutions();
}
//---------------------------------------------------------------------