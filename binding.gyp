{
  "targets": [
    {
      "target_name": "ComputingNode",
      "sources": [
        "./src/main.cpp",
        "./src/nan_basic.cpp",
        "./src/basic.cpp",
        "./src/convert.cpp"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ],
}