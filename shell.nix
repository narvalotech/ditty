{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    cmake
    gcc
    ninja
    gcc-arm-embedded
    picotool
    pkg-config
    xorg.libX11
    xorg.libXrandr
    xorg.libXi
    xorg.libXcursor
    xorg.libXinerama
    libGL
    alsa-lib
    mesa
  ];

  shellHook = ''
    export LD_LIBRARY_PATH=${pkgs.lib.makeLibraryPath [
      pkgs.xorg.libX11
      pkgs.xorg.libXrandr
      pkgs.xorg.libXi
      pkgs.xorg.libXcursor
      pkgs.xorg.libXinerama
      pkgs.libGL
      pkgs.alsa-lib
    ]}:$LD_LIBRARY_PATH
  '';
}