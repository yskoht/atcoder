k, n = gets.chomp.split.map(&:to_i)
as = gets.chomp.split.map(&:to_i)

ds = []
(n-1).times do |i|
  ds.push as[i+1] - as[i]
end
ds.push k - as[n-1] + as[0]

puts k - ds.max
