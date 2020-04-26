n = gets.chomp.to_i
as = gets.chomp.split.map(&:to_i)

res = Array.new(n, 0)

as.each do |a|
  res[a - 1] += 1
end

res.each do |r|
  puts r
end