n, m, x = gets.chomp.split.map(&:to_i)

cs = []
as = []
n.times do
  t = gets.chomp.split.map(&:to_i)
  cs.push t[0]
  as.push t[1..-1]
end

res = 1<<60

(2**n).times do |i|
  xs = Array.new(m, 0)
  tmp = 0

  n.times do |k|
    if (i >> k & 1) == 1
      tmp += cs[k]
      as[k].each.with_index do |a, i|
        xs[i] += a
      end
    end
  end

  if xs.all? { |xx| xx >= x }
    res = [res, tmp].min
  end
end

if res == 1<<60
  puts -1
else
  puts res
end