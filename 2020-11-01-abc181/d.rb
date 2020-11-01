
s = gets.chomp

if s.size == 1
  r = 8
  l = 10
elsif s.size == 2
  r = 16
  l = 100
else
  r = 104
  l = 1000
end

a = []
t =r
while t < l
  d = t.to_s.split('').map(&:to_i).tally
  a.push d unless d.key?(0)
  t += 8
end

b = s.split('').map(&:to_i).tally

ff = false

a.each do |t|
  f = true
  t.each do |k, v|
    unless b.key?(k) && b[k] >= v
      f = false
      break
    end
  end

  if f == true
    ff = true
    break
  end
end

if ff
  puts "Yes"
else
  puts "No"
end
