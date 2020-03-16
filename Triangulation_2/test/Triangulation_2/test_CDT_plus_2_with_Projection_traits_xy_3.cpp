#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Constrained_Delaunay_triangulation_2.h>
#include <CGAL/Constrained_triangulation_plus_2.h>
#include <CGAL/Projection_traits_xy_3.h>
#include <cassert>
#include<boost/range/counting_range.hpp>
typedef CGAL::Exact_predicates_inexact_constructions_kernel EIK;
typedef CGAL::Projection_traits_xy_3<EIK>                   K;
typedef CGAL::Triangulation_vertex_base_2<K>                Vb;
typedef CGAL::Constrained_triangulation_face_base_2<K>      Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb>         TDS;
typedef CGAL::Exact_predicates_tag                          Itag;
typedef CGAL::Constrained_Delaunay_triangulation_2<K, TDS, Itag> CDTi;
typedef CGAL::Constrained_triangulation_plus_2<CDTi> CDT;

typedef CDT::Point Point;
typedef CDT::Vertex_handle Vertex_handle;

int main()
{
  CDT cdt;

  std::vector<std::pair<Vertex_handle, Vertex_handle> > constraints;
  std::vector<std::pair<Point,Point> > segments;

  segments.push_back(std::make_pair(Point(212.69651243, 168.58113131, 0),
                                    Point(212.69487813, 169.35340097, 0)));
  segments.push_back(std::make_pair(Point( 211.49303932, 161.00812931, 0),
                                    Point(211.49303932, 172.95244391, 0)));
  segments.push_back(std::make_pair(Point( 210.13500000, 169.20200000, 0),
                                    Point(232.65300000, 167.91200000, 0)));
  segments.push_back(std::make_pair(Point( 210.13500000, 169.20200000, 0),
                                    Point(232.69100000, 189.32500000, 0))); 

  Point p, q;
  for(const auto& i : segments){
    p = i.first;
    q = i.second;
    Vertex_handle v = cdt.insert(p);
    Vertex_handle w = cdt.insert(q);
    constraints.push_back(std::make_pair(v,w));
  }
  for(const auto& i : boost::counting_range(0,static_cast<int>(constraints.size()))){
    std::cerr << i << std::endl;
    cdt.insert_constraint(constraints[i].first,constraints[i].second);
  }
  std::cerr << "done" << std::endl;
  return 0;
}
