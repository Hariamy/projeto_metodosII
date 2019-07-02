#ifndef MN_PVI
#define MN_PVI

#include <Eigen/Dense>

struct MN_amb_pvi{
  private:
	int dim;
	double t0;
	Eigen::VectorXd S0;
	Eigen::VectorXd (*f)(double t, Eigen::VectorXd S);


  public:
	MN_amb_pvi(int n, double t, Eigen::VectorXd S, Eigen::VectorXd (*f)(double t, Eigen::VectorXd S));
	Eigen::VectorXd euler(double t, int npassos);
	Eigen::VectorXd rungeKutta(double t, int npassos);


};



#endif
