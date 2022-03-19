{
  "targets": [
    {
      "target_name": "ComputingNode",
      "sources": [
        "./src/main.cpp",
        "./src/nan_helpers.cpp",
        "./src/nan_algorithm.cpp",
        "./src/nan_basic.cpp",
        "./src/nan_matrix.cpp",
        "./src/algorithm.cpp",
        "./src/basic.cpp",
        "./src/matrix.cpp",
        "./src/convert.cpp"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ],
}