// ---------------- Elements ----------------

const statusBadge = document.getElementById("status");
const clock = document.getElementById("clock");

const temp = document.getElementById("temperature");
const hum = document.getElementById("humidity");

const pressure = document.getElementById("pressure");

const voltage = document.getElementById("voltage");
const current = document.getElementById("current");

const x = document.getElementById("x");
const y = document.getElementById("y");
const z = document.getElementById("z");

// ---------------- Clock ----------------

function updateClock() {

    const now = new Date();

    clock.innerHTML = now.toLocaleString();

}

setInterval(updateClock,1000);

updateClock();

// ---------------- Charts ----------------

const labels=[];

const tempValues=[];
const pressureValues=[];
const voltageValues=[];

const xValues=[];
const yValues=[];
const zValues=[];

function addData(chart,label,data){

    chart.data.labels.push(label);

    chart.data.datasets.forEach(ds=>{

        ds.data.push(data.shift());

    });

}

const tempChart=new Chart(document.getElementById("tempChart"),{

    type:'line',

    data:{

        labels:labels,

        datasets:[{

            label:'Temperature',

            data:tempValues,

            borderColor:'#00d4ff',

            tension:.3

        }]

    },

    options:{

        responsive:true,

        animation:false

    }

});

const pressureChart=new Chart(document.getElementById("pressureChart"),{

    type:'line',

    data:{

        labels:labels,

        datasets:[{

            label:'Pressure',

            data:pressureValues,

            borderColor:'#00ff88',

            tension:.3

        }]

    },

    options:{

        responsive:true,

        animation:false

    }

});

const batteryChart=new Chart(document.getElementById("batteryChart"),{

    type:'line',

    data:{

        labels:labels,

        datasets:[{

            label:'Voltage',

            data:voltageValues,

            borderColor:'#ffd43b',

            tension:.3

        }]

    },

    options:{

        responsive:true,

        animation:false

    }

});

const accelChart=new Chart(document.getElementById("accelChart"),{

    type:'line',

    data:{

        labels:labels,

        datasets:[

            {

                label:'X',

                data:xValues,

                borderColor:'red'

            },

            {

                label:'Y',

                data:yValues,

                borderColor:'green'

            },

            {

                label:'Z',

                data:zValues,

                borderColor:'cyan'

            }

        ]

    },

    options:{

        responsive:true,

        animation:false

    }

});

// ---------------- Live API ----------------

async function updateLive(){

    try{

        const response=await fetch("/api/live");

        const data=await response.json();

        temp.innerHTML=data.temperature+" °C";
        hum.innerHTML=data.humidity+" %";

        pressure.innerHTML=data.pressure;

        voltage.innerHTML=data.voltage+" V";
        current.innerHTML=data.current+" A";

        x.innerHTML=data.x;
        y.innerHTML=data.y;
        z.innerHTML=data.z;

        if(data.status==="online"){

            statusBadge.innerHTML="Online";

            statusBadge.className="badge bg-success";

        }

        else{

            statusBadge.innerHTML="Offline";

            statusBadge.className="badge bg-danger";

        }

        const t=new Date().toLocaleTimeString();

        labels.push(t);

        tempValues.push(data.temperature);
        pressureValues.push(data.pressure);
        voltageValues.push(data.voltage);

        xValues.push(data.x);
        yValues.push(data.y);
        zValues.push(data.z);

        if(labels.length>20){

            labels.shift();

            tempValues.shift();
            pressureValues.shift();
            voltageValues.shift();

            xValues.shift();
            yValues.shift();
            zValues.shift();

        }

        tempChart.update();

        pressureChart.update();

        batteryChart.update();

        accelChart.update();

    }

    catch(e){

        console.log(e);

    }

}

setInterval(updateLive,1000);

updateLive();