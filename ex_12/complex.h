#pragma once

class t_complex {
private:
	float re, im;

public:
	t_complex();
	t_complex(float re, float im);
	t_complex(const t_complex &a);

	float get_real(void);
	void set_real(float re);

	float get_imaginar(void);
	void set_imaginar(float im);

	void aduna(const t_complex& a);
	void scade(const t_complex& a);
	void inmulteste(const t_complex& a);

	void aduna(const t_complex& a, const t_complex& b);
	void scade(const t_complex& a, const t_complex& b);
	void inmulteste(const t_complex& a, const t_complex& b);

	float modul(void);
};