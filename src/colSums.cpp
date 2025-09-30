#include "MMatrix.h"
#include <cstdint> // for int16_t
#include <Rcpp.h>
#include "apply.h"

class cs {
  public:

    template<typename T, int T2>
    inline void operator()(Rcpp::XPtr<houba::MMatrix<T>> instanc, Rcpp::Vector<T2> result) {
      instanc->colSums(result);
    }

    template<typename T, typename T2>
    inline void operator()(Rcpp::XPtr<houba::MMatrix<T>> instanc, Rcpp::XPtr<houba::MMatrix<T2>> result) {
      instanc->colSums(*result);
    }
};


// ------- result est un R vector -------------
// [[Rcpp::export]]
void colSums_R_double(SEXP pM, std::string datatype, Rcpp::NumericVector result) {
  cs x;
  apply_R(pM, datatype, result, x);
}

// [[Rcpp::export]]
void colSums_R_int(SEXP pM, std::string datatype, Rcpp::IntegerVector result) {
  cs x;
  apply_R(pM, datatype, result, x);
}

// -------- result est un pointeur vers une mmatrix de type restype 
// [[Rcpp::export]]
void colSums_mvector(SEXP pM, std::string datatype, SEXP result, std::string restype) {
  cs x;
  apply_mmatrix(pM, datatype, result, restype, x);
}

