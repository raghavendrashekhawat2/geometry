// Boost.Geometry

// Copyright (c) 2017, Oracle and/or its affiliates.
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_PROJECTIONS_ELLPS_HPP
#define BOOST_GEOMETRY_PROJECTIONS_ELLPS_HPP


#include <boost/geometry/core/srs.hpp>


namespace boost { namespace geometry
{
    
namespace projections
{

namespace detail
{

inline double b_from_a_rf(double a, double rf)
{
    return a * (1.0 - 1.0 / rf);
}

} // namespace detail

} // namespace projections

#define BOOST_GEOMETRY_PROJECTIONS_DETAIL_REGISTER_ELLPS(NAME, TAG) \
namespace traits { \
template <> struct tag<NAME > { typedef TAG type; }; \
template <> struct radius_type<NAME > { typedef double type; }; \
template <std::size_t Dimension> \
struct radius_access<NAME, Dimension> \
{ \
    static inline double get(NAME const& s) \
    { \
        return s.template get_radius<Dimension>(); \
    } \
    static inline void set(NAME& s, double const& value) \
    { \
        s.template set_radius<Dimension>(value); \
    } \
}; \
}

#define BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_B(NAME, A, B) \
namespace projections { namespace ellps { \
struct NAME \
    : srs::spheroid<double> \
{ \
    NAME() \
        : srs::spheroid<double>(A, B) \
    {} \
}; \
}} \
BOOST_GEOMETRY_PROJECTIONS_DETAIL_REGISTER_ELLPS(projections::ellps::NAME, srs_spheroid_tag)

#define BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(NAME, A, RF) \
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_B(NAME, A, detail::b_from_a_rf(A, RF))

#define BOOST_GEOMETRY_PROJECTIONS_DETAIL_SPHER_R(NAME, R) \
namespace projections { namespace ellps { \
struct NAME \
    : srs::sphere<double> \
{ \
    NAME() \
        : srs::sphere<double>(R) \
    {} \
}; \
}} \
BOOST_GEOMETRY_PROJECTIONS_DETAIL_REGISTER_ELLPS(projections::ellps::NAME, srs_sphere_tag)


BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(MERIT, 6378137.0, 298.257)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(SGS85, 6378136.0, 298.257)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(GRS80, 6378137.0, 298.257222101)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(IAU76, 6378140.0, 298.257)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_B (airy, 6377563.396, 6356256.910)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(APL4_9, 6378137.0, 298.25)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(NWL9D, 6378145.0, 298.25)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_B (mod_airy, 6377340.189, 6356034.446)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(andrae, 6377104.43, 300.0)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(aust_SA, 6378160.0, 298.25)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(GRS67, 6378160.0, 298.2471674270)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(bessel, 6377397.155, 299.1528128)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(bess_nam, 6377483.865, 299.1528128)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_B (clrk66, 6378206.4, 6356583.8)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(clrk80, 6378249.145, 293.4663)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(CPM, 6375738.7, 334.29)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(delmbr, 6376428.0, 311.5)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(engelis, 6378136.05, 298.2566)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(evrst30, 6377276.345, 300.8017)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(evrst48, 6377304.063, 300.8017)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(evrst56, 6377301.243, 300.8017)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(evrst69, 6377295.664, 300.8017)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(evrstSS, 6377298.556, 300.8017)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(fschr60, 6378166.0, 298.3)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(fschr60m, 6378155.0, 298.3)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(fschr68, 6378150.0, 298.3)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(helmert, 6378200.0, 298.3)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(hough, 6378270.0, 297.0)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(intl, 6378388.0, 297.0)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(krass, 6378245.0, 298.3)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(kaula, 6378163.0, 298.24)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(lerch, 6378139.0, 298.257)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(mprts, 6397300.0, 191.0)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_B (new_intl, 6378157.5, 6356772.2)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_B (plessis, 6376523.0, 6355863.0)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_B (SEasia, 6378155.0, 6356773.3205)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_B (walbeck, 6376896.0, 6355834.8467)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(WGS60, 6378165.0, 298.3)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(WGS66, 6378145.0, 298.25)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(WGS72, 6378135.0, 298.26)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_ELLPS_A_RF(WGS84, 6378137.0, 298.257223563)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_SPHER_R   (sphere, 6370997.0)
BOOST_GEOMETRY_PROJECTIONS_DETAIL_SPHER_R   (WGS84_sphere, 6378137.0)

}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_PROJECTIONS_ELLPS_HPP
