#pragma once

class t_coeficienti {
private:
	float a, b, c;
public:
	t_coeficienti();
	t_coeficienti(const t_coeficienti&);

	void set_a(float a);
	void set_b(float b);
	void set_c(float c);

	float get_a(void);
	float get_b(void);
	float get_c(void);

	t_coeficienti& operator=(const t_coeficienti& sursa);
	t_coeficienti& operator=(const float sursa);
};
