// Copyright (c) 2010 GeometryFactory (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org)
//
// $URL$
// $Id$
// SPDX-License-Identifier: LGPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Sebastien Loriot
//

#ifndef CGAL_INTERSECTIONS_3_PLANE_3_TETRAHEDRON_3_H
#define CGAL_INTERSECTIONS_3_PLANE_3_TETRAHEDRON_3_H

#include <CGAL/Plane_3.h>
#include <CGAL/Tetrahedron_3.h>

#include <CGAL/Intersections_3/internal/Tetrahedron_3_Unbounded_3_do_intersect.h>

namespace CGAL {
  CGAL_DO_INTERSECT_FUNCTION(Tetrahedron_3, Plane_3, 3)
}

#endif // CGAL_INTERSECTIONS_3_PLANE_3_TETRAHEDRON_3_H
