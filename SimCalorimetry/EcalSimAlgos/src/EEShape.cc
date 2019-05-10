#include <cmath>

#include "SimCalorimetry/EcalSimAlgos/interface/EEShape.h"

void EEShape::fillShape(float& time_interval,
                        double& m_thresh,
                        EcalShapeBase::DVec& aVec,
                        const edm::EventSetup* es) const {
  if (m_useDBShape) {
    if (es == nullptr) {
      throw cms::Exception("EcalShapeBase:: DB conditions are not available, const edm::EventSetup* es == nullptr ");
    }
    edm::ESHandle<EcalSimPulseShape> esps;
    es->get<EcalSimPulseShapeRcd>().get(esps);

    aVec = esps->endcap_shape;
    time_interval = esps->time_interval;
    m_thresh = esps->endcap_thresh;
  } else {
    m_thresh = 0.00025;
    time_interval = 1.0;
    aVec.reserve(500);
    aVec = {
        9.09091e-05,  9.96016e-05,  8.08219e-05,  0.000119685,  9.56522e-05,  0.000143969,  0.000101639,  0.000115789,
        8.31461e-05,  0.000117091,  0.000141224,  5.38745e-05,  0.000158079,  0.000104906,  7.91946e-05,  8e-05,
        0.000119703,  9.96516e-05,  8.82591e-05,  0.000146988,  0.000120588,  9.89474e-05,  0.000116788,  0.000151292,
        0.000108434,  0.000108651,  8.5259e-05,   0.000146575,  8.66142e-05,  0.000103679,  0.000153307,  7.80328e-05,
        8.42105e-05,  0.000114607,  6.90909e-05,  9.22449e-05,  8.92989e-05,  0.000105677,  9.58491e-05,  0.000107383,
        8.85714e-05,  0.000119703,  0.000141463,  0.000122267,  6.0241e-05,   0.000120588,  0.000115789,  0.000121168,
        8.04428e-05,  9.39759e-05,  3.391e-05,    -7.72908e-05, 5.61644e-05,  0.000181102,  -3.67893e-05, 6.45914e-05,
        2.68852e-05,  -1.57895e-05, -2.47191e-05, -5.30909e-05, -1.06122e-05, -3.69004e-06, 5.85153e-05,  -3.54717e-05,
        -9.39597e-06, 5e-05,        -3.19703e-05, 3.69338e-05,  -0.000169231, -4.09639e-05, -1.61765e-05, -8.21053e-05,
        6.86131e-05,  -6.12546e-05, -6.50602e-05, 2.56055e-05,  -3.90438e-05, -5.89041e-05, 0.000195276,  -7.29097e-05,
        1.32296e-05,  3.27869e-06,  -6.31579e-05, -3.37079e-05, 5.16364e-05,  -4.97959e-05, 8.92989e-05,  0.000561572,
        0.00171698,   0.0035906,    0.00742143,   0.01249,      0.020922,     0.030336,     0.043588,     0.0593529,
        0.0764947,    0.0958978,    0.11567,      0.137087,     0.160643,     0.188973,     0.218062,     0.240682,
        0.265773,     0.293327,     0.320832,     0.348689,     0.374411,     0.403575,     0.431147,     0.458644,
        0.488217,     0.515254,     0.53902,      0.566819,     0.589752,     0.615587,     0.63808,      0.664137,
        0.687959,     0.707379,     0.726826,     0.747043,     0.762952,     0.781342,     0.799515,     0.818559,
        0.832301,     0.846658,     0.860791,     0.874009,     0.886242,     0.896982,     0.908713,     0.9189,
        0.9283,       0.938453,     0.945995,     0.95186,      0.958876,     0.963283,     0.968989,     0.972846,
        0.977824,     0.981341,     0.982743,     0.984082,     0.986609,     0.985925,     0.984707,     0.981384,
        0.980941,     0.980132,     0.978176,     0.975987,     0.973396,     0.970395,     0.967422,     0.96346,
        0.959622,     0.955396,     0.950846,     0.945995,     0.940835,     0.935373,     0.929544,     0.923836,
        0.91787,      0.910812,     0.903924,     0.897669,     0.89127,      0.884613,     0.878051,     0.867734,
        0.856756,     0.848477,     0.842189,     0.833787,     0.825903,     0.817931,     0.8102,       0.802771,
        0.79388,      0.785348,     0.777295,     0.767854,     0.759619,     0.752358,     0.743394,     0.736674,
        0.726982,     0.719321,     0.708937,     0.700003,     0.693202,     0.685961,     0.676889,     0.670513,
        0.658788,     0.648343,     0.639381,     0.632761,     0.623614,     0.616164,     0.607884,     0.601437,
        0.593944,     0.585817,     0.577248,     0.570328,     0.56147,      0.553509,     0.548765,     0.539964,
        0.53343,      0.525787,     0.519868,     0.510817,     0.503274,     0.498478,     0.493058,     0.484176,
        0.479896,     0.469998,     0.462893,     0.45576,      0.450375,     0.442683,     0.437887,     0.430736,
        0.427216,     0.420775,     0.41485,      0.407769,     0.403546,     0.397028,     0.389534,     0.388569,
        0.380296,     0.375312,     0.369457,     0.365884,     0.358889,     0.353344,     0.350364,     0.347136,
        0.33872,      0.336706};

    for (unsigned int i(250); i != 500; ++i)
      aVec.push_back(exp(2.63163e-01 - 1.37795e-02 * (i - 151.0)));
  }
}
