{
  pkgs ? import <nixpkgs> { },
}:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc-arm-embedded
    python3
    clang
    clang-tools
    bear
    compdb
    neovim-unwrapped
    fish

    wl-clipboard
    git
    ripgrep
    fd
    nodejs
  ];

  shellHook = ''
    export CPATH=""
    export C_INCLUDE_PATH=""
    export CPLUS_INCLUDE_PATH=""
    export NIX_CFLAGS_COMPILE=""
    export NIX_CFLAGS_LINK=""
    export NIX_LDFLAGS=""
    source ./pros/bin/activate
    echo "✅ PROS dev shell ready!"
    exec fish
  '';
}
