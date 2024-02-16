{
  description = "Ray Tracer written in C, compiled with Zig";

  inputs = {
    flake-parts.url = "github:hercules-ci/flake-parts";
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    devshell.url = "github:numtide/devshell";

    zig.url = "github:mitchellh/zig-overlay";
    zls.url = "github:zigtools/zls";
  };

  outputs = inputs@{ flake-parts, zig, zls, ... }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      imports = [
        inputs.devshell.flakeModule
      ];

      systems = [
        "aarch64-darwin"
        "aarch64-linux"
        "x86_64-darwin"
        "x86_64-linux"
      ];

      perSystem = { pkgs, system, ... }: {
        devshells.default = {
          packages = with pkgs; [
            gnumake
            gcc
            SDL2.dev
            zig.packages.${system}.master
            zls.packages.${system}.zls
          ];
        };
      };
    };
}

