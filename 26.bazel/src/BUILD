cc_library(
    name = "libhello",
    srcs = ["hello.cc"],
    hdrs = ["hello.h"],
)

cc_binary(
    name = "hello_world",
    srcs = [
        "main.cc",
    ],
    deps = ["//src:libhello"],
)
