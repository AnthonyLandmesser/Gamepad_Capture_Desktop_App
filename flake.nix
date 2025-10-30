{
  description = "Gamepad viewer application"; # does not create desktop app just executable

  inputs.nixpkgs.url = "nixpkgs/nixos-25.05";

  outputs = { self, nixpkgs}:
    let
      supportedSystems = [ "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin" ];
      forAllSystems = nixpkgs.lib.genAttrs supportedSystems;
      nixpkgsFor = forAllSystems (system: import nixpkgs { inherit system; });
    in {

      # nix develop (unused)

      # nix build (command unused but needed for nix run)
      packages = forAllSystems (system:
        let
          pkgs = nixpkgsFor.${system};
        in {
          default = pkgs.stdenv.mkDerivation {
            name = "Gamepad-Capture";
            src = ./.;
            nativeBuildInputs = with pkgs; [
              cmake
              ccache
              ninja
            ];
            buildInputs = with pkgs; [
              # reduce build dependencies once prototype works
              qt6.full
            ];
            cmakeFlags = [
              "-DCMAKE_BUILD_TYPE=Release"
            ];
          };
          debug = self.packages.${system}.default.overrideAttrs (old: {
            cmakeFlags = [
              "-DCMAKE_BUILD_TYPE=Debug"
            ];
            CXXFLAGS = "-fsanitize=address -g";
            LDFLAGS = "-fsanitize=address";
          });
        }
      );

      # nix run
      apps = forAllSystems (system:
        {
          default = {
            type = "app";
            program = "${self.packages.${system}.default}/bin/Gamepad-Capture";
          };
          debug = {
            type = "app";
            program = "${self.packages.${system}.debug}/bin/Gamepad-Capture";
          };
        }
      );
    };
}
