const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimise = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{ .name = "main", .strip = true, .target = target, .optimize = optimise });
    exe.linkLibC();
    exe.addCSourceFiles(.{ .root = b.path("src"), .files = &.{ "main.c", "conversion.c", "portion.c", "shoppinglist.c" } });
    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    const run_step = b.step("run", "run the exe");
    run_step.dependOn(&run_cmd.step);
}
