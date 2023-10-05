#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct Point {
    double x, y, z;
};

double calcDistance(double x1, double y1, double z1, 
                    double x2, double y2, double z2) {
  
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

int main() {

  std::ifstream fin("input.txt");
  std::ofstream fout("output.txt");

  std::vector<Point> points;
  double x, y, z;

  while (fin >> x >> y >> z) {
      
      Point p = {x, y, z};
      points.push_back(p);
  }

  for (size_t i = 0; i < points.size(); ++i) {
      for (size_t j = i + 1; j < points.size(); ++j) {
        
          double distance = calcDistance(points[i].x, points[i].y, points[i].z,
                                         points[j].x, points[j].y, points[j].z);
          fout << "Distance between points " << i + 1 << " and " 
                << j + 1 << " is: " << distance << "\n";
      }
  }

  std::sort(points.begin(), points.end(), 
            [](const Point& a, const Point& b) {
                
      return calcDistance(0, 0, 0, a.x, a.y, a.z) < calcDistance(0, 0, 0, b.x, b.y, b.z);
      }
  );

  std::ofstream foutSorted("output_sorted.txt");
  for (const auto& point : points) {
      double distance = calcDistance(0, 0, 0, point.x, point.y, point.z);
      foutSorted << "Distance from origin to point: (" << point.x << ", " 
                 << point.y << ", " << point.z << ") is: "
                 << distance << "\n";
    }

  fin.close();
  fout.close();
  foutSorted.close();

	return 0;
}