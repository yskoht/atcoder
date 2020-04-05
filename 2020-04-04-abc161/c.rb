n, k = gets.chomp.split.map(&:to_i)

if n >= k
  x = n / k
  n = n - x * k
end

puts [n, (n - k).abs].min