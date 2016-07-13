/*~--------------------------------------------------------------------------~*
 *  @@@@@@@@  @@           @@@@@@   @@@@@@@@ @@
 * /@@/////  /@@          @@////@@ @@////// /@@
 * /@@       /@@  @@@@@  @@    // /@@       /@@
 * /@@@@@@@  /@@ @@///@@/@@       /@@@@@@@@@/@@
 * /@@////   /@@/@@@@@@@/@@       ////////@@/@@
 * /@@       /@@/@@//// //@@    @@       /@@/@@
 * /@@       @@@//@@@@@@ //@@@@@@  @@@@@@@@ /@@
 * //       ///  //////   //////  ////////  //
 *
 * Copyright (c) 2016 Los Alamos National Laboratory, LLC
 * All rights reserved
 *~--------------------------------------------------------------------------~*/

#pragma once

// user incldues
#include "ale/mesh/burton/burton_types.h"
#include "flecsi/mesh/mesh_types.h"


namespace ale {
namespace mesh {


////////////////////////////////////////////////////////////////////////////////
// Expose some types
////////////////////////////////////////////////////////////////////////////////

//! some flexi flags
using flecsi::flecsi_internal;
using flecsi::flecsi_user_space;

////////////////////////////////////////////////////////////////////////////////
//! Type for storing instance of template specialized low level mesh.
////////////////////////////////////////////////////////////////////////////////
template < std::size_t N >
using burton_mesh_topology_t = 
  flecsi::mesh_topology_t< burton_mesh_types_t<N> >;


//! Two dimensional and three dimensional versions
using burton_2d_mesh_topology_t = burton_mesh_topology_t<2>; 
using burton_3d_mesh_topology_t = burton_mesh_topology_t<3>; 


} // namespace
} // namespace
