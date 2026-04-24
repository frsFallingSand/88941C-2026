{
  pkgs ? import <nixpkgs> { },
}:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc-arm-embedded-13
    python3
    clang
    clang-tools
    neovim-unwrapped
    fish

    wl-clipboard
    git
    ripgrep
    fd
    nodejs
    lazygit
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
