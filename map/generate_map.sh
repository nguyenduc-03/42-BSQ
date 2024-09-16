#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 4 ]; then
  echo "Usage: $0 x y density output_file"
  exit 1
fi

# Get the arguments
x=$1
y=$2
density=$3
output_file=$4

# Check if the output file is writable
if [ -e "$output_file" ] && [ ! -w "$output_file" ]; then
  echo "Error: $output_file is not writable"
  exit 1
fi

# Execute the Perl script and redirect the output to the specified file
perl -e '
  use warnings;
  use strict;

  die "program x y density" unless (scalar(@ARGV) == 3);

  my ($x, $y, $density) = @ARGV;

  print "$y.ox\n";
  for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
      if (int(rand($y) * 2) < $density) {
        print "o";
      } else {
        print ".";
      }
    }
    print "\n";
  }
' "$x" "$y" "$density" > "$output_file"

echo "Map has been generated and stored in $output_file"
