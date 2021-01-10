a, b = gets.chomp.split
asum = a.split('').map(&:to_i).sum
bsum = b.split('').map(&:to_i).sum

if asum > bsum
  puts asum
else
  puts bsum
end
