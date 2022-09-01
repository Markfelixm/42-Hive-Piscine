pushd "$(git rev-parse --show-toplevel)" > /dev/null
echo "$(< .gitignore)"
popd > /dev/null
