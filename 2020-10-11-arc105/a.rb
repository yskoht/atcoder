a, b, c, d = gets.chomp.split.map(&:to_i)
if
  a + b + c == d ||
  a + b + d == c ||
  a + b == c + d ||
  a + c + d == b ||
  a + c == b + d ||
  a + d == b + c ||
  a == b + c + d
  puts 'Yes'
else
  puts 'No'
end
