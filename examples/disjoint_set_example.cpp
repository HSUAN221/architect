// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>
#include <vtkio/vtu.hpp>

auto main() -> int {
    std::cout << "=======DisjointSetFixSize======" << std::endl;
    architect::DisjointSetFixSize ds_fix_size(6);
    ds_fix_size.connect(0, 5);
    ds_fix_size.connect(1, 2);
    ds_fix_size.connect(1, 5);
    for (size_t i = 0; i < 6; ++i)
        std::cout << "vertex= " << i << " " << ds_fix_size.findSet(i) << std::endl;

    std::cout << "=======DisjointSet======" << std::endl;
    architect::DisjointSet ds;
    std::vector<size_t> vertrex_list{5, 0, 1, 2, 3, 101};
    for (const auto& v : vertrex_list)
        ds.makeSet(v);

    ds.connect(0, 5);
    ds.connect(1, 2);
    ds.connect(1, 101);
    ds.connect(0, 101);
    for (const auto& v : vertrex_list)
        std::cout << "vertex= " << v << " " << ds.findSet(v) << std::endl;

    int rows = 10000, cols = 10000;
    architect::DomainBuilder db(rows, cols);
    db.build();
    auto domain = db.parse();

    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         std::cout << domain[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }


    std::cout << "into labeling..." << std::endl;
    architect::Timer t1;
    t1.start();
    architect::Labeling label(domain);
    auto labels = label.getDomainSet();
    t1.stop();
    std::cout << rows * cols << " " << t1.elapsedTime() << std::endl;

    std::ofstream output("data/output.txt");
    for (int i = 0; i < labels.size(); ++i) {
        for (int j = 0; j < labels[0].size(); ++j) {
            output << std::setw(5) << labels[i][j] << " ";
        }
        output << std::endl;
    }
    output.close();

    /// viewer
    using vtkio::Vtu;
    using vtu_type = vtkio::Vtu;
    using vtk_field_format_type = vtkio::VtkFieldFormat;


    // create unstructured grid dataset
    auto grid = Vtu::createDataset<int>();

    // edit points & edit cells & edit cell data
    auto& points = grid.points();
    auto& point_data = grid.point_data();
    auto& air = point_data.createField("void", vtk_field_format_type::kScalars, 1);
    for (int i = 0; i < labels.size(); ++i) {
        for (int j = 0; j < labels[0].size(); ++j) {
            points.addPoint(i, j, 0);
            if (labels[i][j] > 0)
                air.addData() = {labels[i][j]};
            else
                air.addData() = {-100};
        }
    }


    /// new vtu file
    Vtu vtu;

    /// open vtu file
    vtu.open("void.vtu");

    // output unstructured grid data
    if (vtu)
      vtu << grid;

    // close vtu file
    vtu.close();
    return 0;
}
