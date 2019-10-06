#pragma once

#include "solutie.h"

class t_solutii {
private:
	t_solutie x1, x2;
public:
	t_solutii();
	t_solutii(const t_solutii&);

	void set_x1(t_solutie& x1);
	void set_x2(t_solutie& x2);

	t_solutie get_x1(void);
	t_solutie get_x2(void);

	t_solutii& operator=(const t_solutii& sursa);
	t_solutii& operator=(const float sursa);
};
