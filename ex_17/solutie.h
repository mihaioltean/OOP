#pragma once

class t_solutie {
private:
	float re, im;
public:
	t_solutie();
	t_solutie(float re, float im);
	t_solutie(const t_solutie&);

	void set_re(float re);
	void set_im(float im);

	float get_re(void);
	float get_im(void);

	t_solutie& operator=(const t_solutie& sursa);
	t_solutie& operator=(const float sursa);

};