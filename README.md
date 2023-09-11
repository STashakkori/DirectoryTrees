# DirectoryTrees
Cross-platform console tool that takes a directory path, traverses it recursively, then writes the tree to output path

Output looks like this:
[D] "Root_Directory"
  [F] "DirectoryTrees.cpp"
  [F] "DirectoryTrees.vcxproj"
  [F] "DirectoryTrees.vcxproj.filters"
  [F] "DirectoryTrees.vcxproj.user"
  [D] "x64"
    [D] "Debug"
      [F] "DirectoryTrees.Build.CppClean.log"
      [F] "DirectoryTrees.exe.recipe"
      [F] "DirectoryTrees.ilk"
      [F] "DirectoryTrees.log"
      [F] "DirectoryTrees.obj"
      [D] "DirectoryTrees.tlog"
        [F] "CL.command.1.tlog"
        [F] "Cl.items.tlog"
        [F] "CL.read.1.tlog"
        [F] "CL.write.1.tlog"
        [F] "DirectoryTrees.lastbuildstate"
        [F] "link.command.1.tlog"
        [F] "link.read.1.tlog"
        [F] "link.write.1.tlog"
      [F] "DirectoryTrees.vcxproj.FileListAbsolute.txt"
      [F] "vc143.idb"
      [F] "vc143.pdb"

Where [D] is for directory, [F] is for file, [S] for symlink, [O] for other file types

If you want to see more features for this, let me know. -$t@$h
