#ifndef controller_h
#define controller_h

#include "model.h"
#include "view.h"
#include "events.h"

class t_eq2_controller:t_abstract_controller {
private:
	t_eq2_model* eq2_model;
	t_eq2_view* eq2_view;
public:
	t_eq2_controller(t_eq2_model* eq2_model, t_eq2_view* eq2_view);
	void read_eq2_coeficients(void);
	void solve(void);
	void print_solutions(void);

	void notify(void);
};

#endif